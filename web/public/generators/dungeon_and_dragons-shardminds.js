(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$dungeon_and_dragons$shardminds(){var a=["Adu","Ama","Ani","Ar","Arsha","Ashi","Ashtu","Bala","Bara","Basha","Beles","Delu","Di","Dura","Duru","Enu","Eri","Eshu","Hua","Hun","Il","Ilu","Ira","Ish","Ku","Kua","Kuba","Lu","Mani","Mara","Mashi","Na","Nara","Nashi","Nu","Rua","Run","Sana","Sari","Selu","Shir","Suma","Tab","Tin","Tiru","Uba","Uku","Ura","Ut","Zaki"],r=["ba","bam","bani","bu","ha","hara","hu","ka","ku","lazu","lua","mea","nar","nara","naram","naru","nashtu","ni","niri","nu","nua","pana","ram","ranu","rashi","raya","ri","rin","runu","shara","shari","shi","shti","shtu","shu","sunu","ta","tana","tani","tari","ti","tira","tiru","tua","tum","wia","ya","yara","yua","zu"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*a.length),rnd2=Math.floor(Math.random()*r.length),names=a[rnd]+r[rnd2],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["dungeon_and_dragons-shardminds"] = function(type) {
    return generator$dungeon_and_dragons$shardminds(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
