(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$nato(){var a=["Alfa","Bravo","Charlie","Delta","Echo","Foxtrot","Golf","Hotel","India","Juliett","Kilo","Lima","Mike","November","Oscar","Papa","Quebec","Romeo","Sierra","Tango","Uniform","Victor","Whiskey","Xray","Zulu"],o=Math.floor(Math.random()*a.length),r=Math.floor(Math.random()*(a.length-1));return r>=o&&(r+=1),a[o]+" "+a[r]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-nato"] = function(type) {
    return generator$military$nato(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
