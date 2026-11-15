(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$numeric(){var e=["Nadazero","Unaone","Bissotwo","Terrathree","Kartefour","Pantafive","Soxisix","Setteseven","Oktoeight","Novenine"],t=Math.floor(Math.random()*e.length),r=Math.floor(Math.random()*(e.length-1));return r>=t&&(r+=1),e[t]+" "+e[r]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-numeric"] = function(type) {
    return generator$military$numeric(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
