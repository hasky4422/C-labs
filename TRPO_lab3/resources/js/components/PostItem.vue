<template>
    <div class="post">
      <div class="box1"><img :src="post.image" alt="" height="125" style="border-radius: 0.25rem;"></div>
    <div>
      <div
          @click="$router.push(`/posts/${post.id}`)"
          style="cursor:pointer; margin-left: 10px; font-size:22px"
      >{{ post.name }}
      </div>
      <div class="date">
        <p>{{ post.location }}</p>
      </div>

    </div>
    <div class="post__btns">
    <!--  <my-button
          @click="$emit('remove', post)">
        Удалить
      </my-button>       -->
    </div>
  </div>
</template>

<script>
export default {
  props: {
    post: {
      type: Object,
      required: true,
    }
  },
}
</script>

<style scoped>
.post {
  height: 150px;
  padding: 10px;
  border: 1px solid black;
  border-radius: 4px;
  margin-top: 15px;
  display: flex;
}

.post__btns {
  display: flex;
}
.date p {
  margin-top: 84px;
  font-size: 12px;
  margin-left: 10px;
}
</style>
