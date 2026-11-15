(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$destiny$fallens(){var r=["b","br","d","dr","f","fr","g","gr","k","kr","n","p","ph","pr","r","s","sk","t","tr","v","vr","w","y","z"],n=["a","e","i","o","y"],t=["g","gr","k","kl","kn","kr","ks","l","ld","lkr","ltr","lv","lz","p","r","rk","rl","rrh","sg","sgr","sk","skr","str","thr","tk","tr","v","vg","vk","vr"],a=["k","ks","ks","ks","n","r","rk","s","s","s","sk"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*t.length),rnd4=Math.floor(Math.random()*n.length),rnd5=Math.floor(Math.random()*a.length),i<5?names=r[rnd]+n[rnd2]+t[rnd3]+n[rnd4]+a[rnd5]:(rnd6=Math.floor(Math.random()*n.length),names=n[rnd6]+r[rnd]+n[rnd2]+t[rnd3]+n[rnd4]+a[rnd5]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["destiny-fallens"] = function(type) {
    return generator$destiny$fallens(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
