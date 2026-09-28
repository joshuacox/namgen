(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$united_states(){var e=["Able","Baker","Charlie","Dog","Easy","Fox","George","How","Item","Jig","King","Love","Mike","Nan","Oboe","Peter","Queen","Roger","Sugar","Tare","Uncle","Victor","William","Xray","Yoke","Zebra"],r=Math.floor(Math.random()*e.length),a=Math.floor(Math.random()*(e.length-1));return a>=r&&(a+=1),e[r]+" "+e[a]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-united_states"] = function(type) {
    return generator$military$united_states(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
