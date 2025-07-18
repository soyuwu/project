let n = document.getElementById("inputSo").value;
let sum=0;
for(let i = 1; i <= n; i=i+2){
    sum+=i;
}
document.getElementById("output2").innerHTML = "Tong tu 1 den " + n + " la: " + sum;