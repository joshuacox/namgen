(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$halo$kig_yars(){var n=["a","e","i","o","u"],r=["b","c","d","g","j","n","k","m","r","t","th","y","z","zh"],a=["b","c","d","g","k","m","n","p","q","r","th","x","z"];return i=Math.floor(10*Math.random()),i<5?(rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*a.length),names=r[rnd]+n[rnd2]+a[rnd3]):(rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*a.length),rnd4=Math.floor(Math.random()*r.length),rnd5=Math.floor(Math.random()*n.length),rnd6=Math.floor(Math.random()*a.length),names=r[rnd]+n[rnd2]+a[rnd3]+" "+r[rnd4]+n[rnd5]+a[rnd6]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["halo-kig_yars"] = function(type) {
    return generator$halo$kig_yars(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
