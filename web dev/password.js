const submit_button = document.getElementById("submit");
const password_length = document.getElementById("password_length");
const password_option = document.getElementById("password_options");

submit_button.addEventListener("click", () => {
    //confirmation that submit has been clicked
    console.log("Submit has been clicked!");

    //checking on the selctions
    console.log("User password length: ", password_length.value);
    console.log("User password option: ", password_option.value);

});