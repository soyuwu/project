const firstParagraph = document.getElementById("firstParagragh")

const myImg = document.querySelector("#myImage")

const languages = document.getElementsByClassName("language-item")

const cards = document.querySelectorAll(".card")

const spanTags = document.getElementsByTagName("span")

function updateContent() {
    firstParagraph.textContent = "New content <strong> bold </strong>"
    
}