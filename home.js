function showFAQs() {
  var faqSection = document.getElementById("faq");

  faqSection.style.display = "block";

  faqSection.scrollIntoView({
    behavior: "smooth"
  });
}

function showReviews() {
  var reviewsSection = document.getElementById("reviews");

  reviewsSection.style.display = "block";

  reviewsSection.scrollIntoView({
    behavior: "smooth"
  });
}

function toggleAnswer(index) {
  var answers = document.getElementsByClassName("faq-answer");
  var buttons = document.getElementsByClassName("faq-btn");

  if (answers[index].style.display === "block") {
    answers[index].style.display = "none";
    buttons[index].innerHTML = "Show Answer";
  } else {
    answers[index].style.display = "block";
    buttons[index].innerHTML = "Hide Answer";
  }
}