(function(root) {
  var i, rnd, rnd2, rnd3, rnd4, rnd5, rnd6, rnd7, rnd8, rnd9, rnd10, rnd11, names, name, lname, name2, name3;
  function generator$doctor_who$silurians(r){var n=["","d","h","k","l","m","r","t"],l=["o","e","a","i"],h=["d","dr","cth","ct","cl","cr","hr","hk","hl","kd","kl","kr","l","lr","ln","n","lm","ml","nl","nr","nl","ld","r","rk","rl"],a=["h","k","l","n","m","r"],t=["e","a","","","",""],d=["d","h","k","l","m","n","r","s","v"],o=["o","e","a"],m=["d","dr","hr","hl","hn","lr","ln","n","lm","ln","ml","mn","l","r","rl","rk","sk","sl","sn","sm","st","str","y"],M=["","","","","","","","h","c","l","n","m","s"];return i=Math.floor(10*Math.random()),1===r?(rnd=Math.floor(Math.random()*d.length),rnd2=Math.floor(Math.random()*o.length),rnd3=Math.floor(Math.random()*m.length),rnd4=Math.floor(Math.random()*o.length),rnd5=Math.floor(Math.random()*M.length),names=d[rnd]+o[rnd2]+m[rnd3]+o[rnd4]+M[rnd5]):(rnd=Math.floor(Math.random()*n.length),rnd2=Math.floor(Math.random()*l.length),rnd3=Math.floor(Math.random()*h.length),rnd4=Math.floor(Math.random()*l.length),rnd5=Math.floor(Math.random()*a.length),rnd6=Math.floor(Math.random()*t.length),names=n[rnd]+l[rnd2]+h[rnd3]+l[rnd4]+a[rnd5]+t[rnd6]),names}
  root.__NAMGEN_GENS = root.__NAMGEN_GENS || {};
  root.__NAMGEN_GENS["doctor_who-silurians"] = function(type) {
    return generator$doctor_who$silurians(type !== undefined ? type : 0);
  };
})(typeof window !== "undefined" ? window : globalThis);
