//
// Created by han on 3/7/24.
//
#include "intersections.h"

Intersections::Intersections(const std::vector<Intersection> &intersections) {
    intersections_ = intersections;
}

Intersection Intersections::operator[](int index) {
    return intersections_[index];
}

size_t Intersections::count() {
    return intersections_.size();
}

std::optional<Intersection> Intersections::hit() const {
    if (intersections_.empty()) {
        return std::nullopt;
    }
    std::optional<Intersection> res = std::nullopt;
    for (auto intersection : intersections_) {
        if (intersection.get_t() < 0) {
            continue;
        }
        if (res == std::nullopt || res.value().get_t() > intersection.get_t()) {
            res = std::optional<Intersection>(intersection);
        }
    }
    return res;
}

void Intersections::merge(Intersections &other) {
    std::vector<Intersection> res;

    auto cur_iter = intersections_.begin();
    auto other_iter = other.intersections_.begin();

    while (cur_iter != intersections_.end() && other_iter != other.intersections_.end()) {
        if (cur_iter->get_t() < other_iter->get_t()) {
            res.push_back(*cur_iter);
            cur_iter++;
        } else {
            res.push_back(*other_iter);
            other_iter++;
        }
    }

    while (cur_iter != intersections_.end()) {
        res.push_back(*cur_iter);
        cur_iter++;
    }
    while (other_iter != other.intersections_.end()) {
        res.push_back(*other_iter);
        other_iter++;
    }
    intersections_ = res;
}

