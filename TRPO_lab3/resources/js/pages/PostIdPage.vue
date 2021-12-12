<template>
  <div class="wrapper">
    <div class="box1"></div>
    <div class="box2">
      <div>
      <span>Название товара</span>
      <span>Цена</span>
      </div>
        <p>На первом фото - пример букета из шоколадок с напитком (подойдет как для женщины так и для мужчины, можно заменить конфеты, напиток, цвет упаковки).
          Цена зависит от наполнения, такой как на фото - ДВЕСТИ ПЯТЬДЕСЯТ.
          Второе фото - нежный букет из трёх роз с шоколадными конфетами Трюфель от АВК - прекрасный подарок, который порадует любого, и для этого не надо особого повода - ПРОСТО ПОДАРИТЕ ЧАСТИЧКУ СВОЕЙ ЛЮБВИ И ВНИМАНИЯ!))
          Конфеты легко извлекаются,а букет может и дальше украшать своим своим видом комнату.
          Высота букета - 35см, оформление в упаковочную бумагу с бантом. Цена сто, если в наличии
          На 3-4 фото - примеры букета на 7 роз (бюджетный подарок).
          На последних фото - оформление презента для мужчины, оформление игристого в виде сладкого ананаса (отличный подарок например коллегам, учителям, врачам), очаровательные корзинки с конфетами в розах.
          Высылаю в другие города, упаковка бесплатно
          Возможно изготовление на заказ с любым количеством конфет и в любом цвете, также изготовление букетов по вашим фотопримерам из интернета
          Пишите, спрашивайте(здесь или на вайбер), дарите красиво!
          Обратите внимания на другие мои объявления - там есть букеты как на заказ, так и в наличии по скидке))</p>
    </div>
    <div class="box3">
      Name
    </div>
    <div class="box4">
Location
    </div>
  </div>
</template>

<script>
import axios from 'axios';
import {params} from "lodash";
export default {
    props:  ['id'],
    mounted() {
        console.log(this.$route.params.id);
        let id = this.$route.params.id;
            axios.get('/api/postid',{params: id} )
                .then(response => (console.log(response)));
    }
}

//$route.params.id
</script>

<style scoped>
.wrapper {
  display: grid;
  grid-template-columns: repeat(16, 1fr);
  grid-auto-rows: 60px;
}

.box1 {
  grid-column-start: 3;
  grid-column-end: 8;
  grid-row-start: 2;
  grid-row-end: 9;
  background-size: 110% 110%;
  background-image: url("../img/1.jpg");
}

.box2 {
  grid-column-start: 3;
  grid-column-end: 15;
  grid-row-start: 10;
  grid-row-end: 16;
  background-size: 100% 100%;
  background-color: gray;
}

.box2 span,p {
  margin-left: 2%;
  margin-top: 1%;
  display: flex;
  flex-wrap: wrap;
  font-size:16px;
}
.box2 p {
  font-size: 14px;
}
.box2 span {
  font-size: 20px;
}
.box3 {
  grid-column-start: 9;
  grid-column-end: 15;
  grid-row-start: 2;
  grid-row-end: 4;
  background-color: teal;

  text-align: center;
}
.box4 {
  text-align: center;
  grid-column-start: 10;
  grid-column-end: 14;
  grid-row-start: 5;
  grid-row-end: 9;
  background-color: darkturquoise;
}

</style>
