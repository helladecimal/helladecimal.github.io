let sidebarFrame = document.getElementById("bar-frame")

function iframe(){
    sidebarFrame.style.height = sidebarFrame.contentWindow.document.body.scrollHeight + 20 + "px";

}

sidebarFrame.addEventListener("load", iframe);

window.iframe = iframe;

let sidebarContainer = document.querySelector(".sidebar.box");

let returntoTop = document.createElement("div");

returntoTop.innerHTML = "return to top";

returntoTop.style.opacity = 0.3;
returntoTop.style.fontSize = "14px";
returntoTop.style.textDecoration = "underline";
returntoTop.onclick = function(){window.scrollTo(0, 0)};
returntoTop.style.cursor = "pointer";

sidebarContainer.appendChild(returntoTop);

