import axios from "axios";
import {ref, onMounted, computed, watch} from 'vue';

export function useNextPosts() {
    const posts = ref([])
    const page = ref(1)
    const totalPages = ref(0)
    const isPostsLoading = ref(true)
    const fetching = async () => {
        try {
            const response = await axios.get('api/posts', {
                params: {
                    page: page.value,
                }
            });
            totalPages.value = Math.ceil(response.data.data.length / 10);
            //console.log(response.data.data.length);
            posts.value = response.data.data;
        } catch (e) {
            alert('Ошибка')
        } finally {
            isPostsLoading.value = false;
            //console.log(page.value)
        }
    }

    return {
        posts, isPostsLoading, totalPages, page
    }
}
