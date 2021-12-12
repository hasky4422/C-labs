<template>
  <div>
    <my-input
        v-model="searchQuery"
        placeholder="Поиск...."
        v-focus
    />
    <div class="app__btns">
      <div class="container">
        <my-select
            style="color: teal; height: 40px; border: 1px solid teal;"
            v-model="selectedSort"
            :options="sortOptions"
        />

      </div>
    </div>

    <my-dialog v-model:show="dialogVisible">
      <post-form
      />
    </my-dialog>
    <post-list
        :posts="sortedAndSearchedPosts"
        v-if="!isPostsLoading"
    />
    <div v-else>Идет загрузка...</div>

      <page-wrapper
          :totalPages="totalPages"
          v-model="page"
          @changePage="changePage"
      />
  </div>
</template>

<script>
import PostForm from "@/components/PostForm";
import PostList from "@/components/PostList";
import MyButton from "@/components/UI/MyButton";
import axios from 'axios';
import MySelect from "@/components/UI/MySelect";
import MyInput from "@/components/UI/MyInput";
import {onMounted, ref, watch} from 'vue'
import {usePosts} from "@/hooks/usePosts";
import useSortedPosts from "@/hooks/useSortedPosts";
import useSortedAndSearchedPosts from "@/hooks/useSortedAndSearchedPosts";
import MyDialog from "@/components/UI/MyDialog";
import PageWrapper from "../components/PageWrapper";
import {useNextPosts} from "../hooks/useNextPosts";

export default {
  components: {
      PageWrapper,
    MyInput,
    MySelect,
    MyButton,
    PostList, PostForm, MyDialog
  },

  data() {
    return {
      dialogVisible: false,
      sortOptions: [
        {value: 'name', name: 'По названию'},
        {value: 'description', name: 'По содержимому'},
      ],
        page : 1,
    }
  },
    methods: {
      changePage(page){
         this.page = page;
      }
    },


  setup(props) {
    const {posts, totalPages, isPostsLoading, page} = usePosts();
      const next = async () => {
          try {
              const response = await axios.get('api/posts', {
                  params: {
                      page: page.value,
                  }
              });
              //console.log(response.data.data.length);
              posts.value = response.data.data;
          } catch (e) {
              alert('Ошибка')
          } finally {
              isPostsLoading.value = false;
              //console.log('Работаем')
          }
      };
      watch(page, next);
    const {sortedPosts, selectedSort} = useSortedPosts(posts);
    const {searchQuery, sortedAndSearchedPosts} = useSortedAndSearchedPosts(sortedPosts);



    return {
      posts,
      totalPages,
      page,
      isPostsLoading,
      sortedPosts,
      selectedSort,
      searchQuery,
      sortedAndSearchedPosts,
    }
  }
}
</script>

<style>

.app__btns {
  margin: 15px 0;
  display: flex;
  justify-content: space-between;
}
</style>
