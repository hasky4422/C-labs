import {createStore} from "vuex";
import {postModule} from "@/store/postModule";

export default createStore({
    state: {
      token: 1,
        realToken:0
    },
    mutations:{
      auth(state){
          state.token +=1;
      },
        takeToken(state){
            state.token +=1;
        }
    },
    modules: {
        post: postModule
    }
})
