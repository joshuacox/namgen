(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$legend_of_zelda$anoukis(){var n=["","","","","b","d","f","g","h","k","l","m","n","p","r","s","t","w","y","z"],o=["a","u","o","e"],r=["u","o","u","o","u","o","oo"];for(i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*n.length),rnd2=Math.floor(Math.random()*o.length),rnd3=Math.floor(Math.random()*r.length),rnd4=Math.floor(Math.random()*n.length);rnd4<4;)rnd4=Math.floor(Math.random()*n.length);return names=n[rnd]+o[rnd2]+n[rnd4]+r[rnd3],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["legend_of_zelda-anoukis"] = function(type) {
    return generator$legend_of_zelda$anoukis(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
