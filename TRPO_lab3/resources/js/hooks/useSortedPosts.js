import {ref, computed} from 'vue'

export default function useSortedPosts(posts) {
    const selectedSort = ref('')
    //console.log(selectedSort)
    const sortedPosts = computed(() => {
        //console.log(selectedSort);
        return [...posts.value].sort((post1, post2) => post1[selectedSort.value]?.localeCompare(post2[selectedSort.value]))
    })

    return {
        selectedSort, sortedPosts
    }
};
