<template>
    <div class="reg">
        <h1>Регистрация</h1>
        <div class="errors" v-if="errors.length">
            <b>Please correct the following error(s):</b>
            <ul>
                <li style="list-style-type: none " v-for="error in errors">{{ error }}</li>
            </ul>
        </div>

        <div class="input">
            <h4>Имя пользователя</h4>
            <my-input v-bind:value="user.name" @input="user.name=$event.target.value"></my-input>
        </div>
        <div>
            <h4>Адресс электронной почты</h4>
            <my-input v-bind:value="user.email" @input="user.email=$event.target.value"></my-input>
        </div>
        <div>
            <h4>Пароль</h4>
            <my-input v-bind:value="user.password" @input="user.password=$event.target.value"></my-input>
        </div>
        <div>
            <h4>Добавьте аватор к своему профилю</h4>
            <my-input type = "file" name="image" @change="fileInputChange" ></my-input>
        </div>
        <my-button @click="createProd">Зарегестрироваться</my-button>
    </div>
</template>

<script>
import axios from "axios";
import $router from "lodash/_SetCache";
import $store from "lodash/seq";

export default {
    data(){
        return{
            errors:[],
            user:{
                name:'',
                email:  '',
                password:'',
            },
            image: null,
            token: null,
        }
    },
    methods:{
        async createProd() {
            // if(this.errors.length)
            // {
            //     this.errors = [];
            // }
            // if(this.user.name.length <2 || this.user.name.length >255)
            // {
            //     this.errors.push('Некорректное имя пользователя');
            // }
            // if(this.user.email.length <5 || this.user.email.length >255 || this.user.email.indexOf("@")>-1)
            // {
            //     this.errors.push('Некорректный адресс электронной почты')
            // }
            // if(this.user.password.length <4 || this.user.password.length >255)
            // {
            //     this.errors.push('Некорректный пароль')
            // }
            // if(this.image === null)
            // {
            //     this.errors.push('Изображение обязательно')
            // }
            // if (this.errors.length)
            // {
            //     for (let key in this.user) {
            //         this.user[key] = '';
            //     }
            // }
            if (this.errors.length ===0)
            {
                let form = new FormData();

                form.append('image', this.image[0])
                for (let key in this.user) {
                    form.append(key, this.user[key]);
                }

                //console.log(form);
                await axios
                    .post('/api/register', form)
                    .catch(error => (console.log(error)))
                    .then(response => (this.token = response));
                console.log(this.$store.token)
                this.$store.commit('auth');
            await this.$router.push(`/posts`);
            }
        },
        fileInputChange(){
            this.image = event.target.files;
        },
    },
}
</script>

<style scoped>
.reg{
    display: flow;
    margin-top: 5px;
    margin-bottom: 5px;
}
.input{
    margin-top: 10px;
    margin-bottom: 10px;
}
.errors{
    margin-top: 10px;
    background-color: lemonchiffon;
    border: 1px solid black;
    border-radius: 8px;
}
</style>
