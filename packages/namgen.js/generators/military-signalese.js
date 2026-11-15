(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$military$signalese(){var e=["Ack","Beer","Charlie","Don","Edward","Freddie","Gee","Harry","Ink","Johnnie","King","London","Emma","Nuts","Oranges","Pip","Queen","Robert","Esses","Toc","Uncle","Vic","William","Xray","Yorker","Zebra"],r=Math.floor(Math.random()*e.length),n=Math.floor(Math.random()*(e.length-1));return n>=r&&(n+=1),e[r]+" "+e[n]}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["military-signalese"] = function(type) {
    return generator$military$signalese(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
