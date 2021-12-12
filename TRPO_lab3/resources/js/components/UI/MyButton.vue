<template>
  <button class="btn">
    <slot></slot>
  </button>
</template>

<script>
export default {
  name: 'my-button'
}
</script>

<style scoped>
.btn {
  padding: 10px 15px;
  background: none;
  color: black;
  border: 1px solid black;
  cursor: pointer;
    border-radius: 4px;
}
</style>
