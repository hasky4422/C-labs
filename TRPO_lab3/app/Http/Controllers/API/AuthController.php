<?php

namespace App\Http\Controllers\API;

use App\Http\Controllers\Controller;
use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Hash;
use Illuminate\Support\Facades\Validator;
use Illuminate\Support\Str;

class AuthController extends Controller
{
    public function register(Request $request)
    {
        $validator = Validator::make($request->all(), [
            'name' => ['required', 'string', 'max:255'],
        'email' => ['required', 'string', 'email', 'max:255', 'unique:users'],
        'password' => ['required', 'string', 'min:4'],
    ]);
    // 1
//    if ($validator->fails()) {
//        return response()->json(['error' => $validator->errors()], 401);
//    }
    // 2
    $input = $request->all();
    $image = $request->file('image')->store('images', 'public');
        $input['password'] = bcrypt($input['password']);
        $user = User::create($input);
        // 3

        $token = $user->createToken(Str::random(40))->plainTextToken;
    //$user = User::create($input);
    // 3
    // 4

    return response()->json(['token' => $token], 200);
}
//public function token(Request $request)
//    {
//        $validator = Validator::make($request->all(), [
//            'email' => ['required', 'string', 'email', 'max:255'],
//            'password' => ['required', 'string', 'min:4'],
//            'device_name' => ['required', 'string']
//        ]);
//
//        if ($validator->fails()) {
//            return response()->json(['error' => $validator->errors()], 401);
//        }
//    // 1
//
//        $user = User::where('email', $request->email)->first();
//    // 2
//
//        if (!$user || !Hash::check($request->password, $user->password) {
//            return response()->json(['error' => 'The provided credentials are incorrect.'], 401)
//        };
//    return response()->json(['token' => $user->createToken($request->device_name)->plainTextToken]);
//    }
}// 4

