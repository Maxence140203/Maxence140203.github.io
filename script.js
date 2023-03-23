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

$(document).ready(function() {
  var slideCount = $('.slide3').length;
  var currentIndex = 0;

  $('.slide3').hide();
  $('.slide3:first').show();

  $('.prev3').click(function() {
    currentIndex -= 1;
    if (currentIndex < 0) {
      currentIndex = slideCount - 1;
    }
    $('.slide3').hide();
    $('.slide3:eq(' + currentIndex + ')').show();
  });

  $('.next3').click(function() {
    currentIndex += 1;
    if (currentIndex > slideCount - 1) {
      currentIndex = 0;
    }
    $('.slide3').hide();
    $('.slide3:eq(' + currentIndex + ')').show();
  });
});

$(document).ready(function() {
  var slideCount = $('.slide4').length;
  var currentIndex = 0;

  $('.slide4').hide();
  $('.slide4:first').show();

  $('.prev4').click(function() {
    currentIndex -= 1;
    if (currentIndex < 0) {
      currentIndex = slideCount - 1;
    }
    $('.slide4').hide();
    $('.slide4:eq(' + currentIndex + ')').show();
  });

  $('.next4').click(function() {
    currentIndex += 1;
    if (currentIndex > slideCount - 1) {
      currentIndex = 0;
    }
    $('.slide4').hide();
    $('.slide4:eq(' + currentIndex + ')').show();
  });
});