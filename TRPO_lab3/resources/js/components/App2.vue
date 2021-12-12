<template>
    <div class="app">
        <h1>Точно зашел в app2</h1>
        <router-view></router-view>
    </div>
</template>

<script>
export default {
    components: {
    }
}
</script>

<style>
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: 'Montserrat';
}

.app {
    padding: 20px;
    margin: 0 15%;
}
</style>
