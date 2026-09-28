(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$telegram(){var r=["Adam","Boston","Chicago","Denver","Edward","Frank","George","Henry","Ida","John","King","Lincoln","Mary","New York","Ocean","Peter","Queen","Roger","Sugar","Thomas","Union","Victor","William","Xray","Young","Zero"],a=Math.floor(Math.random()*r.length),n=Math.floor(Math.random()*(r.length-1));return n>=a&&(n+=1),r[a]+" "+r[n]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-telegram"] = function(type) {
    return generator$military$telegram(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
