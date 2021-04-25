var searchLogo = document.getElementById('search_item'); //获取搜索图标
var searchInput = document.getElementById('search_input'); //获取搜索框

searchLogo.onclick = function() {
    var titleContent = document.querySelectorAll('.odiv'); //获取每一个小li里的标题


    console.log(titleContent.length);
    var searchVal = searchInput.value; //要查找得字符串

    for (var i = 0; i < titleContent.length; i++) {
        var container = document.querySelectorAll('.container');
        var text = titleContent[i].innerHTML;

        console.log(titleContent[i].innerHTML);

        text = text.replace(/<b[^>]*>([^>]*)<\/b[^>]*>/ig, "$1"); //清除格式
        titleContent[i].innerHTML = text;

        var reg = new RegExp("(" + searchVal + ")", "ig");
        text = text.replace(reg, "<b>$1</b>");
        titleContent[i].innerHTML = text;

        var get_b = container[i].getElementsByTagName('b');
        console.log(get_b.length);

        if (get_b.length > 0) {
            container[i].style.display = 'block';
        } else {
            container[i].style.display = 'none';
        }
    }
}

document.addEventListener('keyup', function(e) {
    if (e.keyCode == 13) {
        var titleContent = document.querySelectorAll('.odiv'); //获取每一个小li里的标题


        console.log(titleContent.length);
        var searchVal = searchInput.value; //要查找得字符串

        for (var i = 0; i < titleContent.length; i++) {
            var container = document.querySelectorAll('.container');
            var text = titleContent[i].innerHTML;

            console.log(titleContent[i].innerHTML);

            text = text.replace(/<b[^>]*>([^>]*)<\/b[^>]*>/ig, "$1"); //清除格式
            titleContent[i].innerHTML = text;

            var reg = new RegExp("(" + searchVal + ")", "ig");
            text = text.replace(reg, "<b>$1</b>");
            titleContent[i].innerHTML = text;

            var get_b = container[i].getElementsByTagName('b');
            console.log(get_b.length);

            if (get_b.length > 0) {
                container[i].style.display = 'block';
            } else {
                container[i].style.display = 'none';
            }
        }
    }
})