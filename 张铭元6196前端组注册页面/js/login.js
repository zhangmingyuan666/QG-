let baseUrl = 'http://www.rushmc.top/api/';

let re_btn = document.querySelector('.resignbutton');
let lg_btn = document.querySelector(".submit");
let submit_answer = document.getElementById('submit_answer');
let resign_answer = document.getElementById('resign_answer');
let x = document.querySelectorAll('input');
lg_btn.onclick = function() {
    let data = new FormData()

    data.append('username', document.getElementById('lg_username').value);
    data.append('password', document.getElementById('lg_password').value);

    let xhr_lg = new XMLHttpRequest();
    xhr_lg.open("POST", baseUrl + 'login', true);

    xhr_lg.send(data);

    xhr_lg.onreadystatechange = function() {
        if (xhr_lg.readyState === 4 && xhr_lg.status === 200) {
            let res = JSON.parse(xhr_lg.responseText);

            if (res.code === 200) {
                console.log(res.msg)
                window.location.href = 'index.html'
            } else {
                console.log(res.msg);
                lg_btn.style.border = '#FF0000 2px solid';
                lg_btn.style.backgroundColor = 'rgba(225,0,0,0.3)'
                if (x[0].value.length == '0' || x[1].value.length == '0') {
                    submit_answer.style.display = 'block'
                    submit_answer.innerText = '请将信息输入完全再登录';

                } else {
                    submit_answer.innerText = '账号或密码错误!';
                    submit_answer.style.display = 'block'
                }
            }
        }
    }
}

re_btn.onclick = function() {
    let data = new FormData();

    data.append("username", document.getElementById('re_username').value);
    data.append("password", document.getElementById('re_password').value);
    data.append("phone", document.getElementById('re_phone').value);
    data.append("name", document.getElementById('re_name').value);


    let xhr_re = new XMLHttpRequest();

    xhr_re.open("POST", baseUrl + 'register', true);
    xhr_re.send(data);

    xhr_re.onreadystatechange = function() {
        if (xhr_re.readyState === 4 && xhr_re.status === 200) {

            let res = JSON.parse(xhr_re.responseText);

            if (res.code === 200) {
                console.log(res.msg);
                resign_answer.style.display = "block";
                resign_answer.innerText = "注册成功";
                resign_answer.style.color = 'green';
                resign_answer.style.border = '2px green solid';
                resign_answer.style.background = 'rgba(0,255,0,0.3)';
                re_btn.style.color = 'whitesmoke';
                re_btn.style.border = '2px green solid';
                re_btn.style.background = 'rgba(0,255,0,0.3)';
            } else {
                console.log(res.msg);
                re_btn.style.border = '#FF0000 2px solid';
                re_btn.style.backgroundColor = 'rgba(225,0,0,0.3)'
                resign_answer.style.display = 'block'
                if (x[2].value.length == '0' || x[3].value.length == '0' ||
                    x[4].value.length == '0' || x[5].value.length == '0') {
                    resign_answer.innerText = '请将信息输入完全再注册';
                } else {
                    resign_answer.innerText = '账号已存在，无法注册!';
                    resign_answer.style.background = 'rgba(225, 0, 0, 0.3)'
                    resign_answer.style.color = 'red';
                    resign_answer.style.border = 'red 2px solid';
                }
            }
        }
    }
}