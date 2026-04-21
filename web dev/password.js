const submit_button = document.getElementById("submit");
const password_length = document.getElementById("password_length");
const password_option = document.getElementById("password_options");
let password = "";
const password_area = document.getElementById("password_area");

submit_button.addEventListener("click", async () => {
    //confirmation that submit has been clicked
    console.log("Submit has been clicked!");

    //checking on the selctions
    console.log("User password length: ", password_length.value);
    console.log("User password option: ", password_option.value);

    //opening all the files
    let letters = await opening_file("data/alphabet.txt");
    let numbers = await opening_file("data/numbers.txt");
    let specials = await opening_file("data/special.txt");

    //checking what option the user selcted
    switch (password_option.value) {
        case "a":
            console.log("Letters Only");

            //making a new password
            password = making_password(password, password_length.value, letters);

            console.log(password);

            break;
        case "b":
            console.log("Numbers Only");
            break;
        case "c":
            console.log("Specials Only");
            break;
        case "d":
            console.log("All options");
            break;
        default:
            console.log("No selection");
    }
});

//making the password
function making_password(pass, length, list){
    for (let i = 0; i < length; i++) {
        let random_index = Math.floor(Math.random() * list.length);
        pass = pass + list[random_index];
    }
    return pass;
}

//a function that will open the files
async function opening_file(filename){
    const response = await fetch(filename);
    const text = await response.text();
    return text.split("\n").map(line => line.trim()).filter(Boolean);
}