<template>
  <form @submit.prevent>
    <h4>Создание поста</h4>
    <my-input
      v-focus
      v-model="post.name"
      type="text"
      placeholder="Название"
    />
    <my-input
      v-model="post.location"
      type="text"
      placeholder="Описание"
    />
    <my-button
      style="align-self: flex-end; margin-top: 15px"
      @click="createPost"
    >
      Создать
    </my-button>
  </form>
</template>

<script>

import MyButton from "@/components/UI/MyButton";
import MyInput from "@/components/UI/MyInput";

export default {
  components: {MyButton,MyInput},
  data() {
    return {
      post: {
        name: '',
        location: ''
      }
    }
  },
  methods: {
    createPost() {
      this.post.id = Date.now();
      this.$emit('create', this.post)
      this.post = {
        name: '',
        location: ''
      }
    }
  },
}
</script>

<style scoped>
form {
  display: flex;
  flex-direction: column;
}

</style>
