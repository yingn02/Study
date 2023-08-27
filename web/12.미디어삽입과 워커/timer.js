let i = 0;
let b;

onmessage = function (e) {
    if(e.data == "pause") {
        this.clearTimeout(b); //멈춤
    }
    else if(e.data > 0) {
        i = e.data;
        b = setTimeout("timedCount()",1000); //동작
    }
   
}

function timedCount() {
    i = i + 1;
    postMessage(i);
    b = setTimeout("timedCount()",1000);
}

timedCount();