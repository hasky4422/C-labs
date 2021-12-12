import axios from "axios";
import {ref, onMounted, computed, watch} from 'vue';

export function usePosts() {
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
            totalPages.value = response.data.last_page;
            //console.log(response.data);
            posts.value = response.data.data;
        } catch (e) {
            alert('Ошибка')
        } finally {
            isPostsLoading.value = false;
            //console.log(page)
        }
    }

    onMounted(fetching)

    return {
        posts, isPostsLoading, totalPages, page
    }
}
