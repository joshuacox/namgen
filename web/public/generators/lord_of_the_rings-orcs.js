(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$lord_of_the_rings$orcs(){var r=["b","br","c","cr","d","dr","g","gh","gr","k","kr","l","m","r","s","sh","sr"],n=["a","e","i","o","u","a","e","i","o","u","au"],d=["cb","cd","cr","db","dd","fd","fth","g","gb","gd","gg","gl","gr","gz","h","lcm","ld","lf","lg","rb","rc","rd","rg","rz","shn","thr","z","zb","zg","zr","zz"],h=["c","d","dh","f","g","gh","kh","l","r","rg","sh","t","th","","",""],a=["a","o","u","au"];return i=Math.floor(10*Math.random()),i<5?(rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*d.length),rnd4=Math.floor(Math.random()*n.length),rnd5=Math.floor(Math.random()*h.length),names=r[rnd]+n[rnd2]+d[rnd3]+n[rnd4]+h[rnd5]):(rnd=Math.floor(Math.random()*a.length),rnd2=Math.floor(Math.random()*d.length),rnd3=Math.floor(Math.random()*n.length),rnd4=Math.floor(Math.random()*h.length),names=a[rnd]+d[rnd2]+n[rnd3]+h[rnd4]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["lord_of_the_rings-orcs"] = function(type) {
    return generator$lord_of_the_rings$orcs(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
