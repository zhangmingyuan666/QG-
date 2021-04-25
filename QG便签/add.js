window.onload = function() {
    var oAddlogo = document.getElementById("add_logo");
    var oAddarea = document.getElementById("add_typing");
    var oMessageBox = document.getElementById("messageBox");
    var oInput = document.getElementById("myInput");
    var oInputContent = document.getElementById("myInput_content");
    var oPostBtn = document.getElementById("doPost");
    var flag = 1;

    oAddlogo.onclick = function() {


        if (flag == 1) {
            oAddarea.style.display = 'block';
            flag = 2;
        } else {
            oAddarea.style.display = 'none';
            flag = 1;
        }
    }

    oPostBtn.onclick = function() {
        if (oInput.value) {
            var oCotainer = document.createElement('li');
            oCotainer.className = "container";
            oCotainer.innerHTML = "<a href='javascript:void(0)' class='edit'>编辑</a>" +
                "<a href='javascript:void(0)' class='delete'>删除</a>"
            oMessageBox.appendChild(oCotainer);

            //写入发表留言的时间
            var oTime = document.createElement("div");
            oTime.className = "time";
            var myDate = new Date();
            oTime.innerHTML = myDate.toLocaleString();
            oCotainer.appendChild(oTime);


            //写入留言标题
            var oMessageContent = document.createElement("textarea");
            oMessageContent.disabled = true;
            oMessageContent.className = "message_content";
            oMessageContent.innerHTML = oInput.value;
            oInput.value = "";
            oCotainer.appendChild(oMessageContent);

            //写入留言内容
            var oInput_Content = document.createElement('textarea');
            oInput_Content.className = 'input_content';
            oInput_Content.disabled = true;
            oInput_Content.innerHTML = oInputContent.value;
            oInputContent.value = '';
            oCotainer.appendChild(oInput_Content);

            //写入可被搜索改变格式的内容
            var oDiv = document.createElement('div');
            oDiv.className = 'odiv';
            oDiv.innerHTML = oMessageContent.innerHTML;
            oCotainer.appendChild(oDiv);


            var del = document.querySelectorAll('.delete');
            var edi = document.querySelectorAll('.edit');

            for (var i = 0; i < del.length; i++) {
                del[i].onclick = function() {
                    console.log(i);
                    oMessageBox.removeChild(this.parentNode); //巧妙 多留意
                }

                edi[i].onclick = function() {
                    console.log(i);
                    console.log(this.parentNode.children[4]);
                    // this.parentNode.children[5];

                    this.parentNode.children[3].disabled = !this.parentNode.children[3].disabled;
                    this.parentNode.children[4].disabled = !this.parentNode.children[4].disabled;
                    if (this.parentNode.children[4].disabled == false) {
                        this.parentNode.children[4].style.height = '300px';
                        this.parentNode.children[5].style.display = 'none';
                        this.parentNode.children[3].style.color = 'grey';
                    } else {
                        this.parentNode.children[4].style.height = '17px';
                        this.parentNode.children[5].style.display = 'block';
                        this.parentNode.children[3].style.color = 'transparent';
                    }

                    this.parentNode.children[3].innerHTML = this.parentNode.children[3].value;
                    this.parentNode.children[4].innerHTML = this.parentNode.children[4].value;
                    this.parentNode.children[5].innerHTML = this.parentNode.children[3].innerHTML;
                    console.log(this.parentNode.children[3]);
                    console.log(this.parentNode.children[4]);
                }
            }




        }
    }




}