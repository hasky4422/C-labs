<template>
  <div>
    <h1>Добавление продукта</h1>
      <div class="errors" v-if="errors.length">
          <b>Пожалуйста, исправте ошибки:</b>
      <ul>
          <li style="list-style-type: none " v-for="error in errors">{{ error }}</li>
      </ul>
      </div>
      <div  class="input">
          <h4>Введите название продукта</h4>
          <my-input v-bind:value="product.name" @input="product.name=$event.target.value"></my-input>
      </div>
          <h4>Введите Описание продукта</h4>
          <my-input v-bind:value="product.description" @input="product.description=$event.target.value"></my-input>
      </div>
      <div>
          <h4>Введите Адресс </h4>
          <my-input v-bind:value="product.location"  @input="product.location=$event.target.value"></my-input>
      </div>
      <div>
          <h4>Введите Цену </h4>
          <my-input style="width: 100px" v-bind:value="product.price" @input="product.price=$event.target.value"></my-input>
      </div>
      <div>
          <h4>Добавьте изображение к своему товару </h4>
          <my-input type = "file" name="image" @change="fileInputChange" ></my-input>
      </div>
      <my-button @click="createProd">Добавить</my-button>
</template>

<script>
import MyInput from "../components/UI/MyInput";
import MyButton from "../components/UI/MyButton";
import axios from 'axios';
import $router from "lodash/_SetCache";
export default {
    components: {MyButton, MyInput},
    data(){
        return{
            product:{
                name:'',
                description:'',
                location:'',
                price:'',
            },
            image: null,
            errors:[],
        }
    },
    methods:{
        async createProd() {
            if(this.errors.length)
            {
                this.errors = [];
            }
                if(this.product.name.length <2 || this.product.name.length >50)
                {
                    this.errors.push('Некорректное имя');
                }
                if(this.product.description.length <5 || this.product.description.length >100)
                {
                    this.errors.push('Некорректное описание')
                }
                if(this.product.location.length <5 || this.product.location.length >50)
                {
                    this.errors.push('Некорректнаый адресс')
                }
                if(this.product.price ==="")
                {
                    this.errors.push('Некорректная цена')
                }
                if(this.image === null)
                {
                    this.errors.push('Изображение обязательно')
                }
            if (this.errors.length)
            {
                for (let key in this.product) {
                    this.product[key] = '';
                }
            }
                if (this.errors.length ===0)
                {
                    let form = new FormData();

                form.append('image', this.image[0])
                for (let key in this.product) {
                    form.append(key, this.product[key]);
                }

                console.log(form);
                await axios
                    .post('/api/uploadPost', form)
                    .catch(error => (console.log(error)))
                    // .then(response => (console.log(response)))
                await this.$router.push('/posts');
            }
        },
        fileInputChange(){
            this.image = event.target.files;
        },
    },
}
</script>

<style scoped>
.input{
    margin-top: 20px;
    margin-bottom: 20px;
}
.errors{
    margin-top: 10px;
    background-color: lemonchiffon;
    border: 1px solid black;
    border-radius: 8px;
}
</style>
