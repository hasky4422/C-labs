<template>
  <div class="navbar">
    <div @click="$router.push('/posts')"
         style="
    font-family: 'Montserrat', sans-serif;
    color: white;
    font-weight: 700;
    letter-spacing: 3px;
    font-size: 24pt;
    text-shadow: -3px 2px 2px black;
    cursor: pointer;
    margin-left: 190px;
"
    >DFT
    </div>
    <div class="navbar__btns">
<!--        <select aria-placeholder="Placeholder">-->
<!--            <option>Мои товары</option>-->
<!--            <option>Добавить товар</option>-->
<!--        </select>-->
      <my-button style=" border-radius: 0.25rem;
                 border: 1px solid white;
                 background: #fff;
                 margin-bottom: 20px;
                 color: black;
                 margin-right: 10px"
                 @click="$router.push('/posts')"
      >Главная
      </my-button>
        <my-button @click="Test">
            Проверка
        </my-button>

      <div v-if="$store.state.token ===2" class="dropdown">
        <my-button class="dropbtn"
      >Мой профиль
      </my-button>
          <div class="dropdown-content">
              <a href="#">Мои товары</a>
              <a href="/createPost">Создать объявление</a>
              <hr class="rounded">
              <a href="#" id="exit">Выход</a>
          </div>
      </div>
<div  v-else>
      <my-button style="
      margin-right: 10px;
          border: 1px solid white;
          color: white;"
                 @click="$router.push('/register')">
       Зарагестрироваться
      </my-button>
    <my-button style="
    margin-bottom: 20px;
          border: 1px solid white;
          color: white;"
               @click="$router.push('/register')">
        Войти
    </my-button>
</div>



    </div>
  </div>
</template>

<script>
import MyButton from "@/components/UI/MyButton";
import $store from 'lodash/seq';
import MySelect from "./UI/MySelect";
export default {
  components: {MySelect, MyButton},
data() {
    return {
        navOptions: [
            {value: 'userPosts', name: 'Мои объявления'},
            {value: 'createPost', name: 'Создать объявление'},
            {value: 'favorites', name:  'Избранные'}
        ],

        }
    },
    methods:{
      Test(){
          console.log(this.$store.state.token);
      }
    }
}
</script>

<style scoped>
.navbar {
  height: 5.5rem;
  background-color: #343a40 !important;
  box-shadow: 2px 2px 4px gray;
  display: flex;
  align-items: center;
  padding: 0 15px;
}

.navbar__btns {
  margin-left: auto;
    display: flex;
}
.dropdown {
  position: relative;
  display: inline-block;
    font-family: 'Montserrat', sans-serif;
    font-size:14px;
}

.dropbtn {
    color: white;
    border: 1px solid white;
    cursor: pointer;
}

.dropdown {
    position: relative;
    display: inline-block;
}

.dropdown-content {
    display: none;
    position: absolute;
    background-color: white;
    border: 0.1rem solid #bbb;
    border-radius: 5px;
    min-width: 160px;
    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
    z-index: 1;
}

.dropdown-content a {
    color: black;
    padding: 12px 37px;
    text-decoration: none;
    display: block;
    text-align: center;
}
.rounded{
    border-top: 2px solid #bbb;
    border-radius: 5px;
}
#exit{
    margin: 5px 2px ;
    border-top: 0.1rem solid gray;
    background: #343a40;
    border-radius: 20px;
    color: white;
}

.dropdown-content a:hover {background-color: #f1f1f1}

.dropdown:hover .dropdown-content {
    display: block;
    transition-duration: .2s;
}

.dropdown:hover .dropbtn {
}

</style>


