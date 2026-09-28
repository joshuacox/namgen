(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$doctor_who$daleks(){var a=["C","Ch","D","Dh","G","Gh","K","Kh","R","S","Th","V"],t=["a","aa","e","a","e","a","e","i","o"],n=["c","d","k","m","n","r","s","ss","st","t","th","y"],r=Math.floor(150*Math.random());return i=Math.floor(10*Math.random()),1===r?(names="Exterminate! Exterminate! Exterminate!",9===i&&(names="Just kidding. :) Enjoy this Easter egg.")):(rnd=Math.floor(Math.random()*a.length),rnd2=Math.floor(Math.random()*t.length),rnd3=Math.floor(Math.random()*n.length),names=a[rnd]+t[rnd2]+n[rnd3]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["doctor_who-daleks"] = function(type) {
    return generator$doctor_who$daleks(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
