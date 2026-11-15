(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$harry_potter$goblins(r){var a=["Ad","Ag","Al","Ar","Ban","Bar","Bog","Brag","Brod","Brun","Bug","Ear","Eg","Er","Far","Fil","Frad","Fur","Gar","Gor","Grag","Gran","Grin","Gruk","Gug","Gur","Kar","Kog","Krag","Krug","Kur","Lag","Lar","Lug","Lur","Nad","Nag","Nur","Rag","Ran","Rod","Rog","Ug","Ul","Ur"],g=["git","gok","gor","gott","gras","grat","grot","guff","gus","guss","kar","kit","knas","knus","koff","kor","kras","krat","krus","kus","laff","last","lig","lirg","lok","lor","luff","luk","lus","naff","nar","nast","nok","not","nott","nuff","nuk","nus","raff","ragg","rak","rast","rat","rig","rod"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*a.length),rnd2=Math.floor(Math.random()*g.length),names=a[rnd]+g[rnd2],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["harry_potter-goblins"] = function(type) {
    return generator$harry_potter$goblins(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
