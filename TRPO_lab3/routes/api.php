<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\PostController;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::apiResources([
    'posts' => PostController::class,
]);
//Route::get('/posts', [PostController::class, 'index']);
Route::get('/postid', 'App\Http\Controllers\PostController@show');

Route::middleware('auth:sanctum')->get('/user', function (Request $request) {
    return $request->user();
});

Route::post('/uploadPost',  'App\Http\Controllers\PostController@Post_submit');

//Route::post('/register',  'App\Http\Controllers\AuthController@register');
//Route::post('/login',  'App\Http\Controllers\AuthController@login');
//Route::post('/logout',  'App\Http\Controllers\AuthController@logout');

Route::post('register', 'App\Http\Controllers\API\AuthController@register');

//Route::prefix('sanctum')->namespace('API')->group(function() {
//    Route::post('register', 'App\Http\Controllers\API\AuthController@register');
//    Route::post('token', 'AuthController@token');
//});

Route::middleware('auth:sanctum')->get('/name', function (Request $request) {
    return response()->json(['name' => $request->user()->name]);
});

