(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$fantasy$giants(){var r=["b","c","d","f","g","h","j","k","l","m","n","r","s","t","v","w","x","z","a","b","c","d","f","g","h","j","k","l","m","n","r","s","t","v","w","x","z","ar","br","cr","dr","fr","gr","kr","sr","tr","vr","wr","al","bl","cl","dl","fl","gl","kl","sl","vl","zl","","","","",""],a=["e","i","u","o","a"],o=["b","c","d","f","g","k","l","m","n","r","s","t","w","x","z","","","","","","","","",""],n=["ag","am","as","bar","barg","bog","bor","bos","brog","der","dhor","dius","dor","dus","fius","fum","fur","gan","gant","gar","gi","gir","grog","kaos","karos","kos","krus","las","lith","log","lor","los","malog","mir","mohr","nar","nas","nir","nus","og","om","os","rion","roch","rog","rus","rym","sag","sal","sar","sius","sog","sor","tag","tius","theus","thor","thos","to","tor","vag","ver","var","vir","vog","war","wor","zar","ziar","zus"];return i=Math.floor(10*Math.random()),rnd=Math.floor(Math.random()*r.length),rnd2=Math.floor(Math.random()*a.length),rnd3=Math.floor(Math.random()*o.length),rnd4=Math.floor(Math.random()*n.length),names=r[rnd]+a[rnd2]+o[rnd3]+n[rnd4],names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["fantasy-giants"] = function(type) {
    return generator$fantasy$giants(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
