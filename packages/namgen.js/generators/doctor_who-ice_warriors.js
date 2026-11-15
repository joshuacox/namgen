(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$doctor_who$ice_warriors(){var r=["h","gr","g","gl","k","kr","kl","r","sk","sl","ss","sr","sz","v","vr","xz","x","xr","xzn","z"],n=["a","i","o","e","aa","a","u","a","y","a"],a=["d","dr","kss","ld","m","nt","r","rt","rd","rn","rg","sb","sr","sz","szr","zr","ssb","x","xl","z","zd"],d=["d","dz","k","kz","l","lk","n","r","rd","rzz","rz","rs","x","z"],o=["a","","","","","",""];return i=Math.floor(10*Math.random()),i<5?(rnd=Math.floor(Math.random()*o.length),rnd2=Math.floor(Math.random()*r.length),rnd3=Math.floor(Math.random()*n.length),rnd4=Math.floor(Math.random()*a.length),rnd5=Math.floor(Math.random()*n.length),rnd6=Math.floor(Math.random()*d.length),names=o[rnd]+r[rnd2]+n[rnd3]+a[rnd4]+n[rnd5]+d[rnd6]):(rnd=Math.floor(Math.random()*o.length),rnd2=Math.floor(Math.random()*r.length),rnd3=Math.floor(Math.random()*n.length),rnd6=Math.floor(Math.random()*d.length),names=o[rnd]+r[rnd2]+n[rnd3]+d[rnd6]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["doctor_who-ice_warriors"] = function(type) {
    return generator$doctor_who$ice_warriors(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
