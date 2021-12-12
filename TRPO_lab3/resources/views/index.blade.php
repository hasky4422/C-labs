<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src="{{ asset('js/app.js') }}" defer></script>
    <meta name="csrf-token"  content="{{  csrf_token() }}" >
    <title>Test</title>
</head>
<body class="antialiased">
    <div id="app">
    </div>
<script src="{{ mix('js/app.js') }}"></script>
</body>
</html>
