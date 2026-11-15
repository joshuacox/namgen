(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$legend_of_zelda$minishs(){var r=["B","D","F","G","H","J","K","L","M","N","P","T"],n=["e","i","o","e","i","o","a","u"],a=["b","d","f","g","k","l","m","n","p","r","s","t"],o=["ari","tari","rari"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*a.length),rnd4=Math.floor(Math.random()*o.length),names=r[rnd]+n[rnd2]+a[rnd3]+o[rnd4],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["legend_of_zelda-minishs"] = function(type) {
    return generator$legend_of_zelda$minishs(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
