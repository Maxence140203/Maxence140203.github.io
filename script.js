$(document).ready(function() {
  var slideCount = $('.slide').length;
  var currentIndex = 0;

  $('.slide').hide();
  $('.slide:first').show();

  $('.prev').click(function() {
    currentIndex -= 1;
    if (currentIndex < 0) {
      currentIndex = slideCount - 1;
    }
    $('.slide').hide();
    $('.slide:eq(' + currentIndex + ')').show();
  });

  $('.next').click(function() {
    currentIndex += 1;
    if (currentIndex > slideCount - 1) {
      currentIndex = 0;
    }
    $('.slide').hide();
    $('.slide:eq(' + currentIndex + ')').show();
  });
});

$(document).ready(function() {
  var slideCount = $('.slide2').length;
  var currentIndex = 0;

  $('.slide2').hide();
  $('.slide2:first').show();

  $('.prev2').click(function() {
    currentIndex -= 1;
    if (currentIndex < 0) {
      currentIndex = slideCount - 1;
    }
    $('.slide2').hide();
    $('.slide2:eq(' + currentIndex + ')').show();
  });

  $('.next2').click(function() {
    currentIndex += 1;
    if (currentIndex > slideCount - 1) {
      currentIndex = 0;
    }
    $('.slide2').hide();
    $('.slide2:eq(' + currentIndex + ')').show();
  });
});