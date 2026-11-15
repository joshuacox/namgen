(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$rift$bahmis(a){if(1===a)var n=["Altan","Bat","Bayar","Bolor","Ene","Enkh","Erdene","Gan","Gerel","Hon","Khün","Khen","Khon","Mönkh","Medekh","Munkh","Muuno","Naran","Ner","Od","Ogt","Oyun","Oyuun","Saran","Sertuun","Solon","Ter","Uran"],r=["bileg","bish","chimeg","güi","gerel","go","gorzol","gorzul","jargal","khoi","maa","tsatsral","tsetseg","tungalag","tuyaa","val","zorig"];else var n=["Bat","Batu","Chin","Chuluun","Ene","Enkh","Gan","Khün","Khen","Mönkh","Medekh","Munoo","Naran","Ner","Ogt","Otgon","Sühk","Tömör","Ter","Yul"],r=["baatar","bat","bataar","bayar","bish","bold","güi","gis","jargal","khan","khoi","saikhan","sukh","tulga","zorig"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*n.length),rnd2=Math.floor(Math.random()*r.length),names=n[rnd]+r[rnd2],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["rift-bahmis"] = function(type) {
    return generator$rift$bahmis(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
