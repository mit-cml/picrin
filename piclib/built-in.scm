(define (caar p)
  (car (car p)))

(define (cadr p)
  (car (cdr p)))

(define (cdar p)
  (cdr (car p)))

(define (cddr p)
  (cdr (cdr p)))

(define (list . args)
  args)