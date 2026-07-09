// FILE:  -->
// FOLDER:  -->

// └─       ├─      │

let folderIcon = document.createElement("span");
folderIcon.innerHTML = "";
folderIcon.className = "nerd";

let fileIcon = document.createElement("span");
fileIcon.innerHTML = "";
fileIcon.className = "nerd";

let endBracket = document.createElement("span");
endBracket.innerHTML = "└─ ";
endBracket.className = "bracket";

let bracket = document.createElement("span");
bracket.innerHTML = "├─ ";
bracket.className = "bracket";

let folders = document.querySelectorAll(".folder");

let files = document.querySelectorAll(".file");

folders.forEach(function(folder){
    folder.prepend(folderIcon.cloneNode(true));
});

files.forEach(function(file){
    file.prepend(fileIcon.cloneNode(true));

    if (file.nextSibling != null){
        file.prepend(bracket.cloneNode(true));
    } else {
        file.prepend(endBracket.cloneNode(true));
    }
});