<template>
  <div>
    <p>{{ message }}</p>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      message: '',
    };
  },
  mounted() {
    axios
      .get('http://localhost:3000/hello')
      .then((response) => {
        this.message = response.data;
      })
      .catch((error) => {
        console.log(error);
      });
  },
};
</script>
