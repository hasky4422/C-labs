<template>
    <div class="page__wrapper">
        <div
            v-for="pageNumber in totalPages"
            :key="pageNumber"
            class="page"
            :class="{
            'current-page': page === pageNumber
          }"
            @click="changePageNumber(pageNumber)"
        >
            {{ pageNumber }}
        </div>
    </div>
</template>

<script>
export default {
    data() {
        return{
            page: 1,
        }
    },
    name: "pageWrapper",
    props:{
        totalPages:{
            type:Number,
            required: true,
        }
    },
    methods:{
        changePageNumber(pageNumber) {
            this.page = pageNumber;
            this.$emit('changePage', pageNumber);
            this.$emit('update:page', pageNumber);
        },
    },
}
</script>

<style scoped>
.page__wrapper {
    display: flex;
    margin-top: 15px;
    font-family: 'Montserrat', sans-serif;
}
.page {
    border: 2px solid black;
    padding: 10px;
    margin-left: 4px;
}
.current-page {
    border: 2px solid teal;
}
</style>
