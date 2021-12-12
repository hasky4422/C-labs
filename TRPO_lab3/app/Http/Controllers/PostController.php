<?php

namespace App\Http\Controllers;

use App\Http\Resources\ProductResource;
use App\Models\Product;
use GuzzleHttp\Psr7\Uri;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Storage;

class PostController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return Product[]|\Illuminate\Database\Eloquent\Collection|\Illuminate\Http\Response
     */
    public function index(){
        $uri = Product::paginate(10);
        for($i = 0; $i< $uri->count(); $i++ ){
            $uri[$i]->image =asset('storage/'.  $uri[$i]->image);
        };
//        return ProductResource::collection(Product::all());
//        $product = Product::paginate(10);
        return $uri;
        //return DB::table('products')->paginate(10);
    }
    public function Post_submit(Request $request)
    {
        //dd($request->file('image'));
        $validate = $request->validate([
            'name' => 'required|min:2|max:50',
            'description' => 'required|min:5|max:100',
            'location' => 'required|min:5|max:50',
            'price' => 'required',
            'image' => 'required'
        ]);
        $image = $request->file('image')->store('images', 'public');
        $product = new Product();
        $product->name = $request->input('name');
        //$product->user = Auth::user()->id;
                $product->user = 'hasky';
        $product->description = $request->input('description');
        $product->price = $request->input('price');
        $product->location = $request->input('location');
        //$product->category_id = $request->input('category');
        $product->category_id = 3;
        $product->image = $image;
        $product->save();
//        return($product->name);
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     *
     * @param int $id
     * @return ProductResource
     */
    public function show(Request $request): ProductResource
    {
        return new ProductResource(Product::findOrFail($request[0]));
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        //
    }
}
