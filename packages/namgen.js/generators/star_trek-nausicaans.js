(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$star_trek$nausicaans(r){var n=["","","b","ch","d","dg","gh","g","gr","h","j","k","kl","lh","l","m","n","p","r","s","sh","st","t","th","tl","tr","v","x","y","z"],t=["ae","ee","ei","ou","uu","a","e","i","o","u"],h=["bz","ch","d","g","ggr","gv","h","j","jh","l","lth","lrsh","k","kz","kkz","ktz","m","mmk","n","p","r","rt","rg","rc","sh","th","t","tz","v","y","yk","z","zj","zzg","d","g","h","j","l","k","m","n","p","r","t","v","y","z"],a=["","","c","chk","rdz","g","jz","k","m","n","ng","p","r","rr","rrg","sh","t","th","tz","tkz","x","z"],d=["c","chk","rdz","g","jz","k","m","n","ng","p","r","rr","rrg","sh","t","th","tz","tkz","x","z"];if(i=Math.floor(10*Math.random()),i<5){if(rnd=Math.floor(Math.random()*n.length),rnd2=Math.floor(Math.random()*t.length),rnd3=Math.floor(Math.random()*h.length),rnd4=Math.floor(Math.random()*t.length),rnd5=Math.floor(Math.random()*a.length),rnd2<5)for(;rnd4<5;)rnd4=Math.floor(Math.random()*t.length);names=n[rnd]+t[rnd2]+h[rnd3]+t[rnd4]+a[rnd5]}else rnd=Math.floor(Math.random()*n.length),rnd2=Math.floor(Math.random()*t.length),rnd3=Math.floor(Math.random()*d.length),names=n[rnd]+t[rnd2]+d[rnd3];return names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["star_trek-nausicaans"] = function(type) {
    return generator$star_trek$nausicaans(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
