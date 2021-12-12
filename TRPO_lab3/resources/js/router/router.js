import Main from "@/pages/Main";
import {createRouter, createWebHistory} from "vue-router";
import PostPageCompositionApi from "@/pages/PostPageCompositionApi";
import About from "@/pages/About";
import PostIdPage from "@/pages/PostIdPage";
import CreatePost from "../pages/CreatePost";
import Register from "../pages/Register";
import Login from "../pages/Login";
import {id} from "lodash";


const routes = [
    {
        path: '/',
        component: Main
    },
    {
        path: '/createPost',
        component: CreatePost
    },
    {
        path: '/posts',
        component: PostPageCompositionApi
    },
    {
        path: '/about',
        component: About
    },
    {
        path: '/posts/:id',
        component: PostIdPage,
        props  : id,
    },
    {
        path: '/register',
        component: Register
    },
    {
        path: '/login',
        component: Login
    },
    {
        path: '/logout',
        component: Main
    },
]

const router = createRouter({
    routes,
    history: createWebHistory()
})

export default router;
