(import srfi-1)


;; Gregory Newton Forward Interpolation
;;
;; a [n 0] = a
;; b [n 1] = bn
;; c [n 2] = c((n(n-1))/2!)
;; d [n 3] = d((n(n-1)(n-2))/3!)
;; ....

;; sample function y = x^2 + x^3
(define (func x) (+ (expt x 2) (expt x 3)))

;; map the sample function to a list of sequential integers
(define foo (map func (iota 15)))

;; find the difference of items in a list 
(define (diff l m)
    (if (> (length l) 1)
        (diff (cdr l) (append m (list (- (car (cdr l)) (car l)))))
        m)
    )

;;
(define (process l)
    (if (> (length l) 1)
        (let ((line (diff l '())))
            ;; if all the items in the list are the same
            ;; then exit, otherwise print the line and process it
            (if (> (foldl + 0 line) 0)
                (begin
                    (print line)
                    (process line))
                (void)))
        (void)))

(diff foo '())

(print foo)
(process foo)

(process '(1 2 4 8 16 31 57 99 163)) 



