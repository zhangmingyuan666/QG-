var change1 = document.querySelector('.change1');
var change2 = document.querySelector('.change2');
var denglu = document.querySelector('.denglu');
var resign = document.querySelector('.resign');
var background = document.querySelectorAll('input');
change1.onclick = function() {
    denglu.style.display = 'none';
    resign.style.display = 'block';
}

change2.onclick = function() {
    denglu.style.display = 'block';
    resign.style.display = 'none';
}