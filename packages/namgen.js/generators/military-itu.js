(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$itu(){var a=["Amsterdam","Baltimore","Casablanca","Denmark","Edison","Florida","Gallipoli","Havana","Italia","Jerusalem","Kilogramme","Liverpool","Madagascar","New York","Oslo","Paris","Quebec","Roma","Santiago","Tripoli","Upsala","Valencia","Washington","Xanthippe","Yokohama","Zurich"],o=Math.floor(Math.random()*a.length),r=Math.floor(Math.random()*(a.length-1));return r>=o&&(r+=1),a[o]+" "+a[r]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-itu"] = function(type) {
    return generator$military$itu(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
