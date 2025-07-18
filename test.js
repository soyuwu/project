function check(num) {
    if (num < 2) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) return false;
    }
    return true;
}

function kiemTraSoNguyenTo() {
    let num = document.getElementById("num1").value;
    if (check(Number(num))) {
        document.getElementById("output1").innerHTML = num + " la so nguyen to!";
    } else {
        document.getElementById("output1").innerHTML = num + " khong phai so nguyen to!";
    }
}

function Sum() {
    let n = document.getElementById("num2").value;
    let sum = 0;
    for (let i = 1; i <= Number(n); i += 2) {
        sum += i;
    }
    document.getElementById("output2").innerHTML = "Tong cac so le tu 1 den " + n + " la: " + sum;
}
