(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$doctor_who$zygons(){var r=["B","Br","Cr","D","Dr","G","Gr","K","Kr","R","S","Sr","Str","St","T","Tr","V","Vr"],n=["e","a","o"],o=["d","g","k","l","m","n","s","t","v","w","z"],t=["l","m","n","r","rm","rn","s","st"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*n.length),rnd3=Math.floor(Math.random()*o.length),rnd4=Math.floor(Math.random()*n.length),rnd5=Math.floor(Math.random()*t.length),names=r[rnd]+n[rnd2]+o[rnd3]+n[rnd4]+t[rnd5],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["doctor_who-zygons"] = function(type) {
    return generator$doctor_who$zygons(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
